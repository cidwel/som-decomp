.setcpu "65816"
.segment "CODE"
.org $522D
map_control_0e522d:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E2 ; previous-row copy count
