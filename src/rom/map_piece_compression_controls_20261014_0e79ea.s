.setcpu "65816"
.segment "CODE"
.org $79EA
map_control_0e79ea:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
