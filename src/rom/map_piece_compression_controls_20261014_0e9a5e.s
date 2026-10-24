.setcpu "65816"
.segment "CODE"
.org $9A5E
map_control_0e9a5e:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $B3 ; row-distance/count
