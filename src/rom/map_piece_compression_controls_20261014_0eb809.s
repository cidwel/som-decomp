.setcpu "65816"
.segment "CODE"
.org $B809
map_control_0eb809:
    .byte $EB ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $64 ; distance low bit/count
