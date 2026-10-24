.setcpu "65816"
.segment "CODE"
.org $1C68
map_control_0e1c68:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
