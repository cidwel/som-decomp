.setcpu "65816"
.segment "CODE"
.org $533C
map_control_0d533c:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
