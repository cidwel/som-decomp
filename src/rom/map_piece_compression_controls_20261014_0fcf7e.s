.setcpu "65816"
.segment "CODE"
.org $CF7E
map_control_0fcf7e:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
