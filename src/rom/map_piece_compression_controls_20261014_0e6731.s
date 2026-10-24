.setcpu "65816"
.segment "CODE"
.org $6731
map_control_0e6731:
    .byte $E8 ; backreference distance high bits
    .byte $3A ; distance low bit/count
