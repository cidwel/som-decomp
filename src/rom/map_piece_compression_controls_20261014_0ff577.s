.setcpu "65816"
.segment "CODE"
.org $F577
map_control_0ff577:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E1 ; previous-row copy count
