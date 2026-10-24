.setcpu "65816"
.segment "CODE"
.org $36AA
map_control_0f36aa:
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E3 ; previous-row copy count
