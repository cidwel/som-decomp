.setcpu "65816"
.segment "CODE"
.org $134D
map_control_0e134d:
    .byte $E2 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
