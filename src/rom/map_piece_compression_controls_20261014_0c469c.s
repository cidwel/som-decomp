.setcpu "65816"
.segment "CODE"
.org $469C
map_control_0c469c:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
