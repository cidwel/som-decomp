.setcpu "65816"
.segment "CODE"
.org $6F49
map_control_0f6f49:
    .byte $E8 ; backreference distance high bits
    .byte $33 ; distance low bit/count
    .byte $E7 ; previous-row copy count
