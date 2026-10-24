.setcpu "65816"
.segment "CODE"
.org $561B
map_control_0e561b:
    .byte $E9 ; backreference distance high bits
    .byte $85 ; distance low bit/count
