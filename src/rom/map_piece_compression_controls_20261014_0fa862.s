.setcpu "65816"
.segment "CODE"
.org $A862
map_control_0fa862:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
