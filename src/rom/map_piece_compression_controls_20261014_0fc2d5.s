.setcpu "65816"
.segment "CODE"
.org $C2D5
map_control_0fc2d5:
    .byte $E2 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $59 ; row-distance/count
