.setcpu "65816"
.segment "CODE"
.org $9731
map_control_0f9731:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
