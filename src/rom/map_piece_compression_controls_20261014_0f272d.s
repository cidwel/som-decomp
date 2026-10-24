.setcpu "65816"
.segment "CODE"
.org $272D
map_control_0f272d:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
