import json
import pathlib
import unittest

ROOT = pathlib.Path(__file__).resolve().parents[1]
SCHEMA = json.loads((ROOT / "shared/protocol/schema.json").read_text())

class ProtocolContractTests(unittest.TestCase):
    def test_schema_version_is_one(self):
        self.assertEqual(SCHEMA["properties"]["schema_version"]["const"], 1)

    def test_required_event_fields(self):
        self.assertEqual(set(SCHEMA["required"]), {
            "schema_version", "event_id", "device_id", "event_type", "timestamp", "payload"
        })

    def test_workflow_event_types_exist(self):
        events = set(SCHEMA["properties"]["event_type"]["enum"])
        self.assertTrue({"bin.telemetry", "leanbot.mission", "vision.detection", "process.status"} <= events)

if __name__ == "__main__":
    unittest.main()
