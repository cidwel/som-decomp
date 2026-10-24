.setcpu "65816"
.segment "CODE"
.org $5FC1
map_control_0f5fc1:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
