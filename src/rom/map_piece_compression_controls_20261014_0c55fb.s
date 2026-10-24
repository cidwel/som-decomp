.setcpu "65816"
.segment "CODE"
.org $55FB
map_control_0c55fb:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
