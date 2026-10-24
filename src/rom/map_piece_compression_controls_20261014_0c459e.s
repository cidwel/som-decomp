.setcpu "65816"
.segment "CODE"
.org $459E
map_control_0c459e:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
