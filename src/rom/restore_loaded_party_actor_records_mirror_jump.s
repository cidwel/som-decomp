; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-save-apply.md.
.setcpu "65816"
.smart
.a8
.i16

restore_loaded_party_actor_runtime_and_rebuild_attributes = $4C28

.segment "CODE"
.org $3809
restore_loaded_party_actor_records_mirror_jump:
    jmp restore_loaded_party_actor_runtime_and_rebuild_attributes
