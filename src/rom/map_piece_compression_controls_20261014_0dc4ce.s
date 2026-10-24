.setcpu "65816"
.segment "CODE"
.org $C4CE
map_control_0dc4ce:
    .byte $E1 ; previous-row copy count
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
