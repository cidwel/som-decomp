.setcpu "65816"
.segment "CODE"
.org $7813
map_control_0c7813:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
