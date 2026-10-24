# Sound and sprite public wrappers

C03989/4 is the JSR398D/RTL sound entry actually called by the reconstructed D04DCD magic-level update. C12E8C/4 is the JSR4090/RTL sprite-hide entry actually called by the reconstructed D3EC44 burst-child update. Their full existing sound packet/ACK transfer and sprite/OAM-hide bodies are composed unchanged in a new isolated model; only the two wrappers propose eight new instruction bytes.

Eight directed original calls passed on the first capture after a single smoke. They cover sounds0/1/39/FF with delayed native acknowledgements, and sprite indices0/1/31/63 with M8/M16 on hide entry. D0300/DB7E/X16/binary arithmetic and M8 on sound entry follow the existing native consumers. All four own instruction starts were covered; evidence and dependency hashes are recorded in `data/actor_sound_sprite_public_wrappers_audit.json`. Model, checker, report and coverage are frozen.

The proof compares full WRAM outside the observed native stack, CPU/context, peripherals and ordered audio writes, without hooks. Direct wrapper cases establish these entry contracts; they do not add duplicate source credit to the inner bodies or claim whole level-up/burst-child scheduling.
