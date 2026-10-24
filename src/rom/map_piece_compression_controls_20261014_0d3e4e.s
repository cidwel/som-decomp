.setcpu "65816"
.segment "CODE"
.org $3E4E
map_control_0d3e4e:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E7 ; previous-row copy count
