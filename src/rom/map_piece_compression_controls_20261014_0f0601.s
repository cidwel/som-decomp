.setcpu "65816"
.segment "CODE"
.org $0601
map_control_0f0601:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
