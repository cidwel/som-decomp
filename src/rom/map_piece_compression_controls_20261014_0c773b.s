.setcpu "65816"
.segment "CODE"
.org $773B
map_control_0c773b:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
