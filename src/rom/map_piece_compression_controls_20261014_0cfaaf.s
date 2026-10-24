.setcpu "65816"
.segment "CODE"
.org $FAAF
map_control_0cfaaf:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
