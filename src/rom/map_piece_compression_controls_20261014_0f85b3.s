.setcpu "65816"
.segment "CODE"
.org $85B3
map_control_0f85b3:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E1 ; previous-row copy count
