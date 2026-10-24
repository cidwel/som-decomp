.setcpu "65816"
.segment "CODE"
.org $9E8E
map_control_0f9e8e:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
