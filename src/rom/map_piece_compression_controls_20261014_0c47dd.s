.setcpu "65816"
.segment "CODE"
.org $47DD
map_control_0c47dd:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
