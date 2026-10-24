.setcpu "65816"
.segment "CODE"
.org $0E6A
map_control_0d0e6a:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
