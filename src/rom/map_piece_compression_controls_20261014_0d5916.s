.setcpu "65816"
.segment "CODE"
.org $5916
map_control_0d5916:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
