; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-menu-trajectory.md.
.setcpu "65816"
.smart
.a8
.i16

construct_native_title_load_selection_from_validated_saved_slots = $C75229

.segment "CODE"
.org $2AA9
construct_native_title_page_short_call_wrapper:
    jsl f:construct_native_title_load_selection_from_validated_saved_slots
    rts
