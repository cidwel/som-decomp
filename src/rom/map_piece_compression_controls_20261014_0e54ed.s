.setcpu "65816"
.segment "CODE"
.org $54ED
map_control_0e54ed:
    .byte $DF ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
