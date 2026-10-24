.setcpu "65816"
.segment "CODE"
.org $4CB6
map_control_0c4cb6:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
