.setcpu "65816"
.segment "CODE"
.org $1EB8
map_control_0e1eb8:
    .byte $D4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
