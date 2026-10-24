.setcpu "65816"
.segment "CODE"
.org $9731
map_control_0e9731:
    .byte $D7 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
