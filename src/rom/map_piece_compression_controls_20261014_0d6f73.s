.setcpu "65816"
.segment "CODE"
.org $6F73
map_control_0d6f73:
    .byte $EB ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E1 ; previous-row copy count
