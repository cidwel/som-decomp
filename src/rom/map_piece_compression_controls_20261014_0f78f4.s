.setcpu "65816"
.segment "CODE"
.org $78F4
map_control_0f78f4:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
