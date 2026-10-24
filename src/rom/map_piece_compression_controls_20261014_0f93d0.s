.setcpu "65816"
.segment "CODE"
.org $93D0
map_control_0f93d0:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
