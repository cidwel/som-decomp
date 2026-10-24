.setcpu "65816"
.segment "CODE"
.org $540D
map_control_0f540d:
    .byte $EE ; backreference distance high bits
    .byte $0B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
