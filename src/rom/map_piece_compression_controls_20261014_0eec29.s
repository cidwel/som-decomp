.setcpu "65816"
.segment "CODE"
.org $EC29
map_control_0eec29:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
