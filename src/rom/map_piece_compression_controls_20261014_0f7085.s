.setcpu "65816"
.segment "CODE"
.org $7085
map_control_0f7085:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E4 ; previous-row copy count
