.setcpu "65816"
.segment "CODE"
.org $A687
map_control_0ea687:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
