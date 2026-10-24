.setcpu "65816"
.segment "CODE"
.org $2B09
map_control_0c2b09:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
