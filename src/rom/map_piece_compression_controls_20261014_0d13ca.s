.setcpu "65816"
.segment "CODE"
.org $13CA
map_control_0d13ca:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $98 ; row-distance/count
