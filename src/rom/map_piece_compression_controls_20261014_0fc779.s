.setcpu "65816"
.segment "CODE"
.org $C779
map_control_0fc779:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
