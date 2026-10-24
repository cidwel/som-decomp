.setcpu "65816"
.segment "CODE"
.org $4F4A
map_control_0f4f4a:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
