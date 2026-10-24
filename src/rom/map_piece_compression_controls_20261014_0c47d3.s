.setcpu "65816"
.segment "CODE"
.org $47D3
map_control_0c47d3:
    .byte $EC ; backreference distance high bits
    .byte $85 ; distance low bit/count
