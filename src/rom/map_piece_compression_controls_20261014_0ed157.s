.setcpu "65816"
.segment "CODE"
.org $D157
map_control_0ed157:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
