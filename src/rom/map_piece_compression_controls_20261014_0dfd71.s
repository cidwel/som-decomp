.setcpu "65816"
.segment "CODE"
.org $FD71
map_control_0dfd71:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
