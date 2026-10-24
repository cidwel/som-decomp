.setcpu "65816"
.segment "CODE"
.org $16A1
map_control_0f16a1:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
