; Recovered Secret of Mana USA routine; behaviour documented in docs/maps.md.
.setcpu "65816"
.smart
.a8
.i16

upload_complete_boss_frame = $0266

.segment "CODE"
.org $0009
upload_boss_frame_entry:
    jmp upload_complete_boss_frame
