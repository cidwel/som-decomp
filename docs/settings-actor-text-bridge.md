# Settings actor text publication bridge

C02AFA..C02AFD is a complete four-byte bridge: `JSR $2082` followed by `RTL`. It lets a long call enter the existing near-returning C02082 actor text and palette publication routine. That 37-byte callee already has matching readable source.

Both instruction starts occur in the frozen settings-page capture: twelve complete page/helper calls, totaling 1,388,348 original instructions. Its 378 dependency hashes, ROM, CPU and checker hashes remain unchanged. The new static audit independently assembles the whole bridge and compares all four bytes with the ROM. This reuses genuine execution evidence; it does not claim new executions or a separately verified behavioral model.

The complete bridge is now in the function catalogue with `documented_executed` status and in the source manifest. It adds four matching instruction bytes, using the existing parent proof as evidence. The preserved pre-adoption draft audit reports zero credited bytes at its own checkpoint. The outer menu coordinator and its exceptional paths remain open.
