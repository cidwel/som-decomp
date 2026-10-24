.setcpu "65816"
.segment "CODE"
.org $4753
map_control_0c4753:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
